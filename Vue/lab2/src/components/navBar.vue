<template>
    <nav class="navbar bg-dark" data-bs-theme="dark">
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
