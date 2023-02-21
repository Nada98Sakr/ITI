const container = document.querySelector(".container"),
      myVideo = document.getElementById("vid"),
      progressBar = document.getElementById("progressBar"),
      spanTime = document.getElementById("currTime"),
      playBtn = document.getElementById("playBtn"),
      toStartBtn = document.getElementById("toStartBtn"),
      skipBackward = document.getElementById("skipBackward"),
      skipForward = document.getElementById("skipForward"),
      toEndBtn = document.getElementById("toEndBtn"),
      audioVolume = document.getElementById("audioVolume"),
      muteBtn = document.getElementById("muteBtn"),
      audioSpeed = document.getElementById("audioSpeedBtn"),
      fullScreenBtn = document.getElementById("fullScr");

let vol = 0;

myVideo.addEventListener("timeupdate", (e)=>{
    let {currentTime, duration} = e.target;
    progressBar.value = (currentTime/duration)*100;
    let currentMin = Math.floor(currentTime / 60);
    let currentSec = Math.floor(currentTime - currentMin);
    if (currentSec > 60) {
        currentSec -= 60;
    }
    let durationMin = Math.floor(duration / 60);
    let durationSec = Math.floor(duration - durationMin);
    if(durationSec>60){
        durationSec -= 60;
    }
    spanTime.innerText = `${currentMin}.${currentSec} : ${durationMin}.${durationSec}`;
});

progressBar.addEventListener("input", (e) => {
    myVideo.currentTime = e.target.value;
});

playBtn.addEventListener("click", () => {
    myVideo.paused ? myVideo.play() : myVideo.pause();
});

myVideo.addEventListener("play", () => {
    playBtn.children[0].classList.replace("bi-play-fill", "bi-pause-fill");
})

myVideo.addEventListener("pause", () => {
    playBtn.children[0].classList.replace("bi-pause-fill", "bi-play-fill");
});

toStartBtn.addEventListener("click", () => {
    myVideo.currentTime = 0;
});

toEndBtn.addEventListener("click", () => {
    myVideo.currentTime = myVideo.duration;
});

skipBackward.addEventListener("click", () => {
    myVideo.currentTime -= 5;
});

skipForward.addEventListener("click", () => {
    myVideo.currentTime += 5;
});

audioVolume.addEventListener("input", () => {
    myVideo.volume = audioVolume.value;
    if(audioVolume.value == 0){
        muteBtn.children[0].classList.replace(
          "bi-volume-up-fill",
          "bi-volume-mute-fill"
        );
    }
    else{
        muteBtn.children[0].classList.replace(
          "bi-volume-mute-fill",
          "bi-volume-up-fill"
        );
    }
});

muteBtn.addEventListener("click", () => {
    muteBtn.classList.toggle("muted");
    if(muteBtn.classList.contains("muted")){
        vol = audioVolume.value;
        myVideo.volume = audioVolume.value = 0;
        muteBtn.children[0].classList.replace("bi-volume-up-fill", "bi-volume-mute-fill");
    }
    else{
        myVideo.volume = audioVolume.value = vol;
        muteBtn.children[0].classList.replace("bi-volume-mute-fill", "bi-volume-up-fill");
    }
});

muteBtn.addEventListener("mouseover", () => {
    audioVolume.style.display = "block";
})

muteBtn.addEventListener("mouseleave", () => {
    audioVolume.style.display = "none";
});

audioSpeed.addEventListener("click", () => {
    let list = document.querySelector("#audioSpeed");
    list.style.display = "block";
    list.addEventListener("click", (e) => {
        myVideo.playbackRate = e.target.innerText; 
    })
});

fullScreenBtn.addEventListener("click", () => {
    container.classList.toggle("fullScreen");
    if (container.classList.contains("fullScreen")){
        fullScreenBtn.children[0].classList.replace(
          "bi-fullscreen",
          "bi-fullscreen-exit"
        );
    }else{
        fullScreenBtn.children[0].classList.replace(
          "bi-fullscreen-exit",
          "bi-fullscreen"
        );
    }
});