const board = document.getElementById("drawing-board")
let colour = "black";
let click = false;
let array = []
for (let i = 0; i < 4225; i++) {
    let square = document.createElement("div");
    square.addEventListener("mouseover", changeColour)
    square.setAttribute("id", "drawing-board-div");
    //square.setAttribute("class", "element");
    board.appendChild(square);    
}

function changeColour(){
    if(click){
        this.style.backgroundColor = colour;
    }
}

document.getElementById("drawing-board").addEventListener("click", () => {
    if(click == false)
    {
        click = true;
    }
    else 
    click = false;
})
resetboard = () => {
    board.querySelectorAll("div").forEach((div) => (div.style.backgroundColor = "white"))
}

const colorPicker = document.querySelector('#colorpicker');
colorPicker.addEventListener('change', function() {
    colour = colorPicker.value;
  console.log(colorPicker.value);
})

