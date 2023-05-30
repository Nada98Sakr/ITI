<template>
    <div id="right">
        <div class="card2">
            <div class="avatar2"></div>
            <div class="cover"></div>
            <div class="userinfomain2">
                <h1 style="color: #fff">
                    {{ user.user.first_name }} {{ user.user.last_name }}
                </h1>
                <h2 style="color: #798191">{{ user.user.gender }}</h2>
            </div>
        </div>
    </div>
</template>

<script>
import axios from "axios";
import { reactive } from 'vue'
import { useRoute } from 'vue-router';

export default {
    name: "userDetailsApp",

    setup() {
        const state = reactive({
            user: {}
        });
        
        getuserById();

        function getuserById() {
            const id = useRoute().params.id;
            axios
                .get(` http://localhost:3000/users/${id}`)
                .then((res) => {
                    state.user = res.data;
                })
                .catch((err) => console.log(err));
        }

        function back() {
            this.$router.push("/users");
        }

        return{
            user: state,
            getuserById,
            back
        }
    }
};
</script>

<style lang="css" scoped>

@import url(https://fonts.googleapis.com/css?family=Roboto:400,100,300,500,700,900);
#right {
    width: 50%;
    height: 100%;
    z-index: 1;
    margin: 0 auto;
}
.card2 {
    width: 320px;
    height: 0px;
    background: #2b303b;
    position: absolute;
    z-index: 2;
    top: 50%;
    margin-top: 0px;
    left: 50%;
    margin-left: -160px;
    box-shadow: 5px 5px 10px 2px rgba(0, 0, 0, 0.1);
    overflow: hidden;
    border-radius: 5px;
    cursor: pointer;
    opacity: 1;
    filter: alpha(opacity=100);
    -webkit-animation: card2 2s forwards;
    -webkit-animation-iteration-count: 1;
    -webkit-animation-delay: 0s;
    -webkit-animation: card2 2s forwards;
    animation: card2 2s forwards;
    -webkit-animation-iteration-count: 1;
    animation-iteration-count: 1;
    -webkit-animation-delay: 0s;
    animation-delay: 0s;
    -webkit-transition-timing-function: ease-in-out;
    transition-timing-function: ease-in-out;
    box-sizing: border-box;
    -moz-box-sizing: border-box;
    -webkit-box-sizing: border-box;
    border-left: 0px solid red;
}

@-webkit-keyframes card2 {
    0% {
        opacity: 1;
        filter: alpha(opacity=100);
        width: 320px;
        height: 1px;
        margin-top: 0px;
        border-left: 0px solid #2b303b;
        background: #ccc;
    }
    60% {
        opacity: 1;
        filter: alpha(opacity=100);
        width: 320px;
        height: 1px;
        margin-top: 0px;
        border-left: 320px solid #2b303b;
        background: #ccc;
    }
    61% {
        opacity: 1;
        filter: alpha(opacity=100);
        width: 320px;
        height: 1px;
        margin-top: 0px;
        border-left: 0px solid #2b303b;
        background: #2b303b;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        width: 320px;
        height: 420px;
        margin-top: -210px;
    }
}

@keyframes card2 {
    0% {
        opacity: 1;
        filter: alpha(opacity=100);
        width: 320px;
        height: 1px;
        margin-top: 0px;
        border-left: 0px solid #2b303b;
        background: #ccc;
    }
    60% {
        opacity: 1;
        filter: alpha(opacity=100);
        width: 320px;
        height: 1px;
        margin-top: 0px;
        border-left: 320px solid #2b303b;
        background: #ccc;
    }
    61% {
        opacity: 1;
        filter: alpha(opacity=100);
        width: 320px;
        height: 1px;
        margin-top: 0px;
        border-left: 0px solid #2b303b;
        background: #2b303b;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        width: 320px;
        height: 420px;
        margin-top: -210px;
    }
}

.avatar2 {
    width: 110px;
    height: 110px;
    background: url(https://images.unsplash.com/photo-1429277005502-eed8e872fe52?fit=crop&fm=jpg&h=275&ixlib=rb-0.3.5&q=80&w=400)
        no-repeat center center #fff;
    border-radius: 100%;
    position: absolute;
    z-index: 5;
    left: 50%;
    margin-left: -55px;
    box-sizing: border-box;
    -moz-box-sizing: border-box;
    -webkit-box-sizing: border-box;
    opacity: 0;
    filter: alpha(opacity=0);
    -webkit-animation: avatar 1.5s forwards;
    -webkit-animation-iteration-count: 1;
    -webkit-animation-delay: 1s;
    -webkit-animation: avatar 1.5s forwards;
    animation: avatar 1.5s forwards;
    -webkit-animation-iteration-count: 1;
    animation-iteration-count: 1;
    -webkit-animation-delay: 1s;
    animation-delay: 1s;
    -webkit-transition-timing-function: ease-in-out;
    transition-timing-function: ease-in-out;
    border: 5px solid #2b303b;
}

@-webkit-keyframes avatar {
    0% {
        opacity: 0;
        filter: alpha(opacity=0);
        top: 1000px;
    }
    50% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 125px;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 125px;
    }
}

@keyframes avatar {
    0% {
        opacity: 0;
        filter: alpha(opacity=0);
        top: 1000px;
    }
    50% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 125px;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 125px;
    }
}

.cover {
    width: 0px;
    height: 0px;
    background: url(https://images.unsplash.com/photo-1443527216320-7e744084f5a7?fit=crop&fm=jpg&h=800&ixlib=rb-0.3.5&q=80&w=1200)
        no-repeat center center;
    position: absolute;
    top: 50%;
    left: 50%;
    opacity: 0;
    filter: alpha(opacity=0);
    -webkit-animation: cover 1s forwards;
    -webkit-animation-iteration-count: 1;
    -webkit-animation-delay: 1.5s;
    -webkit-animation: cover 1s forwards;
    animation: cover 1s forwards;
    -webkit-animation-iteration-count: 1;
    animation-iteration-count: 1;
    -webkit-animation-delay: 1.5s;
    animation-delay: 1.5s;
    -webkit-transition-timing-function: ease-in-out;
    transition-timing-function: ease-in-out;
    border-radius: 100%;
}

@-webkit-keyframes cover {
    0% {
        opacity: 0;
        filter: alpha(opacity=0);
        top: 40%;
        left: 50%;
        width: 0px;
        height: 0px;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 20%;
        margin-top: -150px;
        left: 50%;
        margin-left: -250px;
        width: 500px;
        height: 500px;
    }
}

@keyframes cover {
    0% {
        opacity: 0;
        filter: alpha(opacity=0);
        top: 40%;
        left: 50%;
        width: 0px;
        height: 0px;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 20%;
        margin-top: -150px;
        left: 50%;
        margin-left: -250px;
        width: 500px;
        height: 500px;
    }
}

.userinfomain2 {
    width: 320px;
    height: 220px;
    color: #fff;
    position: absolute;
    top: 200px;
    left: 0;
    z-index: 2;
    background: #2b303b;
}

h1,
h2 {
    margin: 0;
    padding: 0;
    font-family: "Roboto", sans-serif;
    width: 100%;
}

h1 {
    text-align: center;
    font-size: 1.7em;
    letter-spacing: -0.02em;
    font-weight: 700;
    color: #2b303b;
    opacity: 0;
    filter: alpha(opacity=0);
    z-index: 2;
    margin-top: 70px;
    -webkit-animation: heading1 0.6s forwards;
    -webkit-animation-iteration-count: 1;
    -webkit-animation-delay: 1.8s;
    -webkit-animation: heading1 1s forwards;
    animation: heading1 1s forwards;
    -webkit-animation-iteration-count: 1;
    animation-iteration-count: 1;
    -webkit-animation-delay: 1.8s;
    animation-delay: 1.8s;
    -webkit-transition-timing-function: ease-in-out;
    transition-timing-function: ease-in-out;
}

@-webkit-keyframes heading1 {
    0% {
        opacity: 0;
        filter: alpha(opacity=0);
        top: 120px;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 65px;
    }
}

@keyframes heading1 {
    0% {
        opacity: 0;
        filter: alpha(opacity=0);
        top: 120px;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 65px;
    }
}

h2 {
    text-align: center;
    font-size: 1em;
    font-weight: 300;
    color: #999;
    opacity: 0;
    filter: alpha(opacity=0);
    z-index: 2;
    -webkit-animation: heading2 0.6s forwards;
    -webkit-animation-iteration-count: 1;
    -webkit-animation-delay: 2.2s;
    -webkit-animation: heading2 0.6s forwards;
    animation: heading2 0.6s forwards;
    -webkit-animation-iteration-count: 1;
    animation-iteration-count: 1;
    -webkit-animation-delay: 2.2s;
    animation-delay: 2.2s;
    -webkit-transition-timing-function: ease-in-out;
    transition-timing-function: ease-in-out;
}

@-webkit-keyframes heading2 {
    0% {
        opacity: 0;
        filter: alpha(opacity=0);
        top: 160px;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 98px;
    }
}

@keyframes heading2 {
    0% {
        opacity: 0;
        filter: alpha(opacity=0);
        top: 160px;
    }
    100% {
        opacity: 1;
        filter: alpha(opacity=100);
        top: 98px;
    }
}
</style>
