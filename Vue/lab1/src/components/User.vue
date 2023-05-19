<template>
    <div> 
        <table class="table table-dark text-center mx-auto w-50 mt-5">
            <thead>
                <tr>
                    <th scope="col">Name</th>
                    <th scope="col">Age</th>
                    <th scope="col">Action</th>
                </tr>
            </thead>
            <tbody>

                <tr v-for="user, index in users" :key="user.name">
                    <td>{{user.name}}</td>
                    <td>{{user.age}}</td>
                    <td><button class="btn btn-danger btn-sm" @click="$emit('deletingUser', index)">Delete</button></td>
                </tr>
            </tbody>
        </table>
    </div>
</template>

<script>
    export default (await import('vue')).defineComponent ({
        name:"userChild",
        props: ['users'],
    });
</script>

<style scoped>
.table{
    border-radius: 5px;
}

</style>