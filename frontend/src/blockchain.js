export default {
  async fetchStories() {
    // TODO Replace this dummy data with data fetched from the blockchain
    return [
      {
        id: 'buggydapp',
        title: 'Dapp Tale',
        content: 'Once upon a time, there was a blockchain dapp who'
      },
      {
        id: 'forkyblock',
        title: 'Adventures of a Forky Block',
        content: 'A block went out to travel through the network when'
      }
    ]
  },
  async createStory(storyId, title) {
    // TODO Send transaction to create the new story in the blockchain
  },
  async addWord(storyId, word) {
    // TODO Send transaction to blockchain to add the new word to the story
  }
}
