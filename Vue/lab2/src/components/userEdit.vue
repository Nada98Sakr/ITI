<template>
    <div class="d-flex justify-content-center my-5">
        <div class="form-container">
            <p class="title">Update User Data</p>
            <form class="form" @submit.prevent="saveUser">
                <div class="input-group">
                    <label for="firstName">First Name</label>
                    <input
                        type="text"
                        name="firstName"
                        id="firstName"
                        v-model="editUser.first_name"
                    />
                </div>
                <div class="input-group">
                    <label for="lastName">Last Name</label>
                    <input
                        type="text"
                        name="lastName"
                        id="lastName"
                        v-model="editUser.last_name"
                    />
                </div>
                <div class="input-group">
                    <label for="gender">Gender</label>
                    <select name="gender" id="gender" v-model="editUser.gender">
                        <option value="male">Male</option>
                        <option value="female">Female</option>
                    </select>
                </div>
                <button class="add">UPDATE</button>
            </form>
        </div>
    </div>
</template>

<script>
import axios from "axios";

export default {
    name: "userEditApp",
    data() {
        return {
            editUser: {},
        };
    },
    created() {
        this.getuserById();
    },
    methods: {
        getuserById() {
            const id = this.$route.params.id;
            axios
                .get(` http://localhost:3000/users/${id}`)
                .then((res) => {
                    this.editUser = res.data;
                })
                .catch((err) => console.log(err));
        },
        saveUser() {
            axios
                .put(
                    ` http://localhost:3000/users/${this.editUser.id}`,
                    this.editUser
                )
                .then(() => {
                    this.$router.push('/users')
                })
                .catch((err) => console.log(err));
            this.editUser = {};
        },
    },
};
</script>

<style lang="css" scoped>
.form-container {
    width: 500px;
    border-radius: 0.75rem;
    background-color: rgba(17, 24, 39, 1);
    padding: 2rem;
    color: rgba(243, 244, 246, 1);
}

.title {
    text-align: center;
    font-size: 1.5rem;
    line-height: 2rem;
    font-weight: 700;
}

.form {
    margin-top: 1.5rem;
}

.input-group {
    margin: 1rem 0;
    font-size: 0.875rem;
    line-height: 1.25rem;
}

.input-group label {
    display: block;
    color: rgba(156, 163, 175, 1);
    margin-bottom: 4px;
}

.input-group input,
.input-group select,
.input-group option {
    width: 100%;
    border-radius: 0.375rem;
    border: 1px solid rgba(55, 65, 81, 1);
    outline: 0;
    background-color: rgba(17, 24, 39, 1);
    padding: 0.75rem 1rem;
    color: rgba(243, 244, 246, 1);
}

.input-group input:focus,
.input-group select:focus,
.input-group option:focus {
    border-color: rgba(167, 139, 250);
}

.add {
    display: block;
    background-color: rgba(167, 139, 250, 1);
    padding: 0.75rem 2rem;
    text-align: center;
    color: rgba(17, 24, 39, 1);
    border: none;
    border-radius: 0.375rem;
    font-weight: 600;
    margin: 2rem auto;
}
</style>
