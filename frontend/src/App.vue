<template>
  <div id="app">
    <img alt="EOS logo" src="./assets/eos-logo.png">
    <div v-for="story in stories" :key="story.name">
      <Story :story="story"/>
    </div>
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
      stories: []
    }
  }
}
</script>
