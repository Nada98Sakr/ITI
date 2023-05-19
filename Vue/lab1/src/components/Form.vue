<template>
    <div class="form-container container mx-auto mt-5">
        <p class="title">Sign up</p>
        <form class="form" @submit.prevent="addUser">
            <div class="input-group">
                <label for="Name">Name</label>
                <input type="text" name="Name" id="Name" placeholder="" v-model="newUser['name']">
            </div>
            <div class="input-group">
                <label for="age">age</label>
                <input type="number" name="age" id="age" placeholder="" v-model.number="newUser['age']">
            </div>
            <div class="my-2">
                <label>
                    <input type="radio" name="role" value="admin" v-model="role" checked >
                    <span>Admin</span>
                </label>
                <label>
                    <input type="radio" name="role" value="user" v-model="role">
                    <span>User</span>
                </label>
            </div>
            <button class="sign">Sign up</button>
        </form>
    </div>
</template>

<script>

    export default {
        name: 'formParent',
        data(){
            return{
                newUser: {
                    name: '',
                    age: '',
                },
                role: 'admin'
            }
        },
        methods:{
            addUser(){
                if (this.role == 'admin') {
                    this.$emit("addingNewAdmin", this.newUser)
                } else {
                    this.$emit("addingNewuser", this.newUser)
                }
                this.newUser = {
                    name: '',
                    age: '',
                }
                this.role = 'admin'
            }
        }
    }
    
</script>

<style scoped>
.form-container {
    width: 320px;
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
    margin-top: 0.25rem;
    font-size: 0.875rem;
    line-height: 1.25rem;
}

.input-group label {
    display: block;
    color: rgba(156, 163, 175, 1);
    margin-bottom: 4px;
}

.input-group input {
    width: 100%;
    border-radius: 0.375rem;
    border: 1px solid rgba(55, 65, 81, 1);
    outline: 0;
    background-color: rgba(17, 24, 39, 1);
    padding: 0.75rem 1rem;
    color: rgba(243, 244, 246, 1);
}

.input-group input:focus {
    border-color: rgba(167, 139, 250);
}

.sign {
    display: block;
    width: 100%;
    background-color: rgba(167, 139, 250, 1);
    padding: 0.75rem;
    text-align: center;
    color: rgba(17, 24, 39, 1);
    border: none;
    border-radius: 0.375rem;
    font-weight: 600;
}

label {
    display: flex;
    cursor: pointer;
    font-weight: 500;
    position: relative;
    overflow: hidden;
    margin-bottom: 0.375em;
}

label input {
    position: absolute;
    left: -9999px;
}

label input:checked + span:before {
    box-shadow: inset 0 0 0 0.4375em #a78bfa;
}

label span {
    display: flex;
    align-items: center;
    padding: 0.375em 0.75em 0.375em 0.375em;
    border-radius: 99em;
    transition: 0.25s ease;
}

label span:hover {
    background-color: #d6d6e5;
}

label span:before {
    display: flex;
    flex-shrink: 0;
    content: "";
    background-color: #fff;
    width: 1.5em;
    height: 1.5em;
    border-radius: 50%;
    margin-right: 0.375em;
    transition: 0.25s ease;
    box-shadow: inset 0 0 0 0.125em #00005c;
}

</style>