<template>
  <navBarApp v-if="!$route.meta.hideNavBar"/>
  <router-view></router-view>
</template>

<script>
import navBarApp from './components/navBar.vue'

export default {
  name: 'App',
  components: {
    navBarApp,
  }
}
</script>

<style>

</style>
