<template>
  <b-card :title="story.title"
          :sub-title="story.id"
          tag="article">
    <p class="card-text">
      {{story.content}}
    </p>
    <b-form inline @submit.prevent="onSubmit(story, word)">
      <b-input class="mb-2 mb-sm-0 mr-0 mr-sm-2" id="search" v-model="word" maxlength="25"/>
      <b-button type=submit variant="primary">
        <i class="fas fa-plus"></i>
        Add word
      </b-button>
    </b-form>
  </b-card>
</template>

<script>
export default {
  props: ['story'],
  data() {
    return { word: '' }
  },
  methods: {
    async onSubmit(story, word) {
      this.word = ''
      await this.addWord(story, word)
    },
    async addWord(story, word) {
      // TODO Send transaction to blockchain to add new word
    }
  }
}
</script>
