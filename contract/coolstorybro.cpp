#include <eosiolib/eosio.hpp>
#include <string>

using eosio::name;
using std::string;

class[[eosio::contract("coolstorybro")]] coolstorybro : public eosio::contract {
  private:
    struct [[eosio::table]] story_type {
        name id;
        string title;
        string content;
        uint64_t primary_key() const { return id.value; }
    };
    typedef eosio::multi_index<"stories"_n, story_type> stories_table;

  public:
    using contract::contract;

    [[eosio::action("createstory")]] void createstory(name id, string title) {
        // Check if title is too long
        eosio_assert(title.length() <= 80, "Title should be at most 80 characters long");

        // Instantiate stories table
        stories_table stories(_self, _self.value);

        // Check if the story ID is already in use
        auto existing = stories.find(id.value);
        eosio_assert(existing == stories.end(), "A story with this ID already exists");

        // Everything went well, let's save the new story in the DB
        stories.emplace(_self, [&](auto &story) {
            story.id = id;
            story.title = title;
        });
    };

    [[eosio::action]] void addword(name id, string word) {
        // Check if word is too long
        eosio_assert(word.length() <= 25, "Word should be at most 25 characters long");
        // Check if it is more than one word
        eosio_assert(word.find_first_of("\t\n ") == string::npos, "Word should not contain any whitespace");

        // Instantiate stories table
        stories_table stories(_self, _self.value);

        // Check if the story exists
        auto story = stories.get(id.value, "No story found with this ID");

        // Update the story, adding the new word
        stories.modify(story, eosio::same_payer, [&](auto &story) {
            story.content += string(" ") + word;
        });
    };
};
EOSIO_DISPATCH(coolstorybro, (createstory)(addword))
