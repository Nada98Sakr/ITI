<template>
    <nav class="navbar bg-dark" v-theme="''">
        <div class="container">
            <router-link :to="`/users`" class="navbar-brand text-light">All Users</router-link>
        </div>
    </nav>
</template>

<script>
export default {
    name: "navBarApp",
};
</script>

<style lang="scss" scoped></style>
