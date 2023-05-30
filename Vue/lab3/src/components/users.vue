<template>
    <table class="table table-dark table-striped table-bordered text-center w-75 mx-auto mt-5">
        <thead>
            <tr>
                <th scope="col">ID</th>
                <th scope="col">First Name</th>
                <th scope="col">Last Name</th>
                <th scope="col">Gender</th>
                <th scope="col">Action</th>
            </tr>
        </thead>
        <tbody>
            <tr v-for="user in users.users" :key="user.id">
                <td>{{ user.id }}</td>
                <td>{{ user.first_name }}</td>
                <td>{{ user.last_name }}</td>
                <td>{{ user.gender }}</td>
                <td>
                    <router-link :to="`/users/view/${user.id}`" class="btn btn-sm btn-dark mx-2"><i class="bx bx-show-alt" style="color: #fff"></i></router-link>
                    <button class="btn btn-sm btn-danger" @click="deleteUser(user.id)"><i class="bx bx-trash"></i></button>
                </td>
            </tr>
        </tbody>
    </table>
</template>

<script>
import axios from "axios";
import { reactive } from 'vue'

export default {
    name: "AllusersApp",
    setup() {
        const state = reactive({
            users: []
        });

        getallusers();

        function getallusers() {
            axios
                .get("  http://localhost:3000/users")
                .then((res) => {
                    state.users = res.data;
                })
                .catch((err) => console.log(err));
        }

        function deleteUser(id) {
            axios
                .delete(`  http://localhost:3000/users/${id}`)
                .then((res) => {
                    console.log(res.data);
                    this.getallusers();
                })
                .catch((err) => console.log(err));
        }

        return {
            users: state,
            getallusers,
            deleteUser
        }
    }
};
</script>

<style></style>
