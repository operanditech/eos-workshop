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
import blockchain from '../blockchain'

export default {
  props: ['story'],
  data() {
    return { word: '' }
  },
  methods: {
    async onSubmit(story, word) {
      await blockchain.addWord(story.id, word)
      this.word = ''
    }
  }
}
</script>
