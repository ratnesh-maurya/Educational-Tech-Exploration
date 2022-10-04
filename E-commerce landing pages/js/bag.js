// Name: HARSH SAXENA
// Roll No: 19/19011

function removeItemFromCart(id) {
    let arr = getCart();

    arr.forEach(element => {
        if(element.id === id){
            let i = arr.indexOf(element);
		    arr.splice(i, 1);
        }
        
        localStorage.setItem('cart-items', JSON.stringify(arr));

    });
    window.location.reload();
}

function getCart() {
    let arr;
    if(localStorage.getItem('cart-items') === null) {
        arr = []
    } else {
        arr = JSON.parse(localStorage.getItem('cart-items'))
    }
    
    return arr
}


//Cart

var cartItems = getCart();
console.log("cart : ",cartItems);
var content = '';
cartItems.map(item => {
    content += `<div class="col-md-6 col-sm-12 my-card" id=${item.id}>`;
    content += `<div class="card text-center">`;
    content += `<img src=${item.img} class="card-img-top" alt=${item.title}>`;
    content += `<div class="card-body"> <h5 class="card-title">${item.title}</h5>`;
    content += `<p class="card-text">${item.price}</p>`;
    content += `<div class="item-details">`;
    content += `<p>Price: ${item.price}</p>`;
    content += `<p>${item.description}</p>`;
    content += `<p>Brand: ${item.brand}</p> </div>`;
    content += `<button class="btn btn-danger p-2" onClick="removeItemFromCart(${item.id})">Remove from Cart</button>`;
    content += `</div> </div> </div>`;
});
document.getElementById("cart-items").innerHTML = content;