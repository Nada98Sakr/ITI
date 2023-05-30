import { createApp } from 'vue'
import App from './App.vue'
import { createWebHistory, createRouter } from "vue-router";
import AllusersApp from "./components/users.vue";
import errorApp from "./components/error.vue";
import userDetailsApp from "./components/userDetails.vue";
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
        path: "/:NotFound(.*)*",
        component: errorApp,
        meta: { hideNavBar: true },
    },
];

const router = createRouter({
    history: createWebHistory(),
    routes,
});

const app = createApp(App)

app.directive("theme", {
    mounted(element, binding) {
        if (binding.value === "dark") {
            element.style.backgroundColor = "#343a40";
            element.style.color = "#eee";
        } else {
            element.style.backgroundColor = "#f8f9fa";
            element.style.color = "#eee";
        }
    },
});

app.use(router).mount('#app')
