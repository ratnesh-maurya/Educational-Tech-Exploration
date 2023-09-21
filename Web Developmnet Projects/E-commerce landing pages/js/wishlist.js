// Name: HARSH SAXENA
// Roll No: 19/19011

function removeItemFromWishlist(id) {
    let arr = getWishlist();

    arr.forEach(element => {
        if(element.id === id){
            let i = arr.indexOf(element);
		    arr.splice(i, 1);
        }
        
        localStorage.setItem('wish-items', JSON.stringify(arr));

    });
    window.location.reload();
}


function getWishlist() {
    let arr;
    if(localStorage.getItem('wish-items') === null) {
        arr = []
    } else {
        arr = JSON.parse(localStorage.getItem('wish-items'))
    }
    console.log(arr);
    return arr
}


//Wishlist
var wishItems = getWishlist();
console.log("wishlist : ",wishItems);
var content = '';
wishItems.map(item => {
    content += `<div class="col-md-6 col-sm-12 my-card" id=${item.id}>`;
    content += `<div class="card text-center">`;
    content += `<img src=${item.img} class="card-img-top" alt=${item.title}>`;
    content += `<div class="card-body"> <h5 class="card-title">${item.title}</h5>`;
    content += `<p class="card-text">${item.price}</p>`;
    content += `<div class="item-details">`;
    content += `<p>Price: ${item.price}</p>`;
    content += `<p>${item.description}</p>`;
    content += `<p>Brand: ${item.brand}</p> </div>`;
    content += `<button class="btn btn-danger p-2" onClick="removeItemFromWishlist(${item.id})">Remove from WishList</button>`;
    content += `</div> </div> </div>`;
});
document.getElementById("wish-items").innerHTML = content;