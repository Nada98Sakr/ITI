<template>
  <div class="text-center">
    <div class="p-3 mb-2 bg-dark text-white">
      <button class="btn px-2 mr-5 btn-space mt-2">
          <span class="button-content text-white" @click="toggleFormToggle">Form</span>
      </button>
      <button class="btn px-2 mr-5 btn-space mt-2"  @click="showAdminToggle"><span class="button-content text-white">Admin</span></button>
      <button class="btn px-2 mr-5 btn-space mt-2" @click="showUserToggle"><span class="button-content text-white">Users</span></button>
    </div>
    <formParent v-if="showForm" @addingNewAdmin="adminAdded" @addingNewuser="userAdded" />
    <adminChild :admins="admins" v-if="showAdmin" @deletingAdmin="deleteAdmin" />
    <userChild :users="users" v-if="showUser" @deletingUser="deleteUser" />
  </div>
</template>

<script>
import formParent from './components/Form.vue';
import adminChild from './components/Admin.vue';
import userChild from './components/User.vue';

export default {
  name: 'App',
  components:{
    formParent,
    adminChild,
    userChild,
  },
  data(){
    return{
      admins: [
        {
          name: 'nada',
          age: 24,
        }
      ],
      users: [
        {
          name: 'nourhan',
          age: 27,
        }
      ],
      showForm: true,
      showAdmin: false,
      showUser: false,
    }
  },
  
  methods: {
    toggleFormToggle(){
    this.showForm = true;
    this.showAdmin = false;
    this.showUser = false;
    },
    showAdminToggle(){
      this.showAdmin = true;
      this.showForm = false;
      this.showUser = false;

    },
    showUserToggle(){
      this.showForm = false;
      this.showUser = true;
      this.showAdmin = false;
    },
    adminAdded(newAdmin) {
      this.admins.push(newAdmin);
    },
    userAdded(newUser) {
      this.users.push(newUser);
      console.log(this.users);
    },
    deleteUser(index) {
      this.users.splice(index, 1);
    },
    deleteAdmin(index) {
      this.admins.splice(index, 1);
    },
  }
}
</script>

<style>

</style>
