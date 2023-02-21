
$(function(){
    let AllList = $(".data");
    AllList.on("click", (e) => {
      if ($(e.target).hasClass("done")) {
        $(e.target).parents("li").children("p").addClass("ItsDone");
      } else if ($(e.target).hasClass("notDone")) {
        $(e.target).parents("li").remove();
      }
    });

    $("form").on("submit", (e) => {
      e.preventDefault();
      AddTask();
    });

    function AddTask(){
      let task = $("#floatingName").val();
      AllList.append(
        `<li class="list-group-item d-flex text-white justify-content-between">
            <p class="NotDoneYet">${task}</p>
            <div class="check">
              <i class="bi bi-check-square-fill text-success done"></i>
              <i class="bi bi-x-square-fill text-danger notDone"></i>
            </div>
        </li>`
      );

      $("#floatingName").val("");
    }
})
