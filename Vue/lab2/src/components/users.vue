<template>
    <div class="d-flex justify-content-end m-5">
        <router-link :to="`/users/create`" class="btn btn-sm btn-success p-2">Create New User</router-link>
    </div>
    <table class="table table-dark table-striped table-bordered text-center w-75 mx-auto">
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
            <tr v-for="user in users" :key="user.id">
                <td>{{ user.id }}</td>
                <td>{{ user.first_name }}</td>
                <td>{{ user.last_name }}</td>
                <td>{{ user.gender }}</td>
                <td>
                    <router-link :to="`/users/edit/${user.id}`" class="btn btn-sm btn-primary mx-2"><i class="bx bxs-edit"></i></router-link>
                    <router-link :to="`/users/view/${user.id}`" class="btn btn-sm btn-dark mx-2"><i class="bx bx-show-alt" style="color: #fff"></i></router-link>
                    <button class="btn btn-sm btn-danger" @click="deleteUser(user.id)"><i class="bx bx-trash"></i></button>
                </td>
            </tr>
        </tbody>
    </table>
</template>

<script>
import axios from "axios";

export default {
    name: "AllusersApp",
    created() {
        this.getallusers();
    },
    data() {
        return {
            users: [],
        };
    },
    methods: {
        getallusers() {
            axios
                .get("  http://localhost:3000/users")
                .then((res) => {
                    this.users = res.data;
                })
                .catch((err) => console.log(err));
        },
        deleteUser(id) {
            axios
                .delete(`  http://localhost:3000/users/${id}`)
                .then((res) => {
                    console.log(res.data);
                    this.getallusers();
                })
                .catch((err) => console.log(err));
        },
    },
};
</script>

<style></style>
