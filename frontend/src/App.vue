<template>
  <div id="app">
    <b-container>
      <div class="header py-4 text-center">
        <img alt="EOS logo" src="./assets/eos-logo.png" width="100px">
        <div class="header-text">
          <h1>EOSIO Workshop</h1>
          <h2>Story Builder</h2>
        </div>
      </div>
      <b-row>
        <b-col>
          <b-form inline class="mb-2">
            <label class="mr-sm-2" for="search">Search</label>
            <b-input class="mb-2 mb-sm-0" id="search" v-model="search"/>
          </b-form>
        </b-col>
        <b-col class="text-right">
          <b-button v-b-modal.createStoryModal>Create new story</b-button>
        </b-col>
      </b-row>
      <div v-for="story in filteredStories" :key="story.name">
        <Story :story="story" class="mb-2"/>
      </div>
    </b-container>
    <b-modal id="createStoryModal" title="Create Story" @ok="createStory(newStory.id, newStory.title)">
      <b-form>
        <b-form-group label="Story ID"
                      label-for="storyId"
                      description="Use this to uniquely reference the story. Same format as EOSIO account names.">
          <b-form-input id="storyId"
                        type="text"
                        maxlength="12"
                        v-model="newStory.id"
                        required
                        placeholder="coolstorybro">
          </b-form-input>
        </b-form-group>
        <b-form-group label="Title"
                      label-for="storyTitle"
                      description="The title of the story. Make it suggest what the story should be about.">
          <b-form-input id="storyTitle"
                        type="text"
                        maxlength="80"
                        v-model="newStory.title"
                        required
                        placeholder="Game of Blocks">
          </b-form-input>
        </b-form-group>
      </b-form>
    </b-modal>
  </div>
</template>

<script>
import Story from './components/Story.vue'

export default {
  name: 'app',
  components: {
    Story
  },
  data() {
    return {
      stories: [
        { id: 'randomstory', title: 'Dapp Tale', content: 'Once upon a time, there was a blockchain dapp' },
        { id: 'anotherstory', title: 'Block Adventures', content: 'A block went out to travel through the network' }
      ],
      search: '',
      newStory: { id: '', title: '' }
    }
  },
  async mounted() {
    // TODO Load stories from blockchain
  },
  computed: {
    filteredStories() {
      if (this.search) {
        return this.stories.filter(s => s.id.includes(this.search) || s.title.includes(this.search))
      } else {
        return this.stories
      }
    }
  },
  methods: {
    createStory(id, title) {
      // TODO Send transaction to create the new story in the blockchain
    }
  }
}
</script>

<style lang="scss" scoped>
.header {
  img {
    vertical-align: top;
  }
  .header-text {
    display: inline-block;
  }
}
</style>
