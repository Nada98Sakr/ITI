import { createApp } from 'vue'
import App from './App.vue'
import { createWebHistory, createRouter } from "vue-router";
import AllusersApp from "./components/users.vue";
import errorApp from "./components/error.vue";
import userDetailsApp from "./components/userDetails.vue";
import createUserApp from "./components/createUser.vue"
import userEditApp from "./components/userEdit.vue"
import "bootstrap/dist/css/bootstrap.min.css";
import "bootstrap/dist/js/bootstrap.min.js";

const routes = [
    {
        path: "/",
        component: AllusersApp,
        alias: "/users",
    },
    {
        path: "/users/view/:id",
        component: userDetailsApp,
    },
    {
        path: "/users/edit/:id",
        component: userEditApp,
    },
    {
        path: "/users/create/",
        component: createUserApp,
    },
    {
        path: "/:NotFound(.*)*",
        component: errorApp,
        meta: { hideNavBar: true },
    },
];

const router = createRouter({
    history: createWebHistory(),
    routes,
});

createApp(App).use(router).mount('#app')
