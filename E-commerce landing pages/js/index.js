// Name: HARSH SAXENA
// Roll No: 19/19011

function addWishlist(title, description, img, price, brand) {

    let arrayItems;
    let my_id;
    arrayItems = getWishlist();
   
    arrayItems.length === 0 ? my_id = 0 : my_id = (arrayItems[arrayItems.length - 1].id) + 1

    var item = {
        id: my_id,
        title: title,
        description: description,
        img: img,
        price: price,
        brand: brand
    }

    arrayItems.push(item);
    console.log(arrayItems);
    localStorage.setItem('wish-items', JSON.stringify(arrayItems));
    alert("Selected Item added to your Wishlist!\nVisit Wishlist to see your items!")
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

//adding and retrieving cart items
function addCart(title, description, img, price, brand) {
    let arrayItems;
    let my_id;
    arrayItems = getCart();
   
    arrayItems.length === 0 ? my_id = 0 : my_id = (arrayItems[arrayItems.length - 1].id) + 1

    var item = {
        id: my_id,
        title: title,
        description: description,
        img: img,
        price: price,
        brand: brand
    }
    arrayItems.push(item);
    localStorage.setItem('cart-items', JSON.stringify(arrayItems));
    alert("Selected Item added to the Cart!\nVisit Cart to see your items!")
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

// utility function to show hidden details
const displayDetails = (id) => {
    var btnText = document.getElementById(`btn-${id}`);

    if(btnText.innerHTML === 'Show details'){
        document.getElementById(`item-details-${id}`).style.display = 'block';
        btnText.innerHTML = '❌';
    }else{
        document.getElementById(`item-details-${id}`).style.display = 'none';
        btnText.innerHTML = 'Show details';
    }
}

var xhr = new XMLHttpRequest();
xhr.onload = () => {
    if(xhr.status === 200){
        responseObject = JSON.parse(xhr.responseText);

        console.log(responseObject);
        var newContent = '';
        responseObject.items.map(item => {
            if(item.category === 'product'){
                newContent += `<div class="col-md-3 col-sm-6 col-xs-12 my-card">`;
                newContent += `<div class="card text-center">`;
                newContent += `<img src=${item.img} class="card-img-top" alt=${item.title}>`;
                newContent += `<div class="card-body"> <h5 class="card-title">${item.title}</h5>`;
                newContent += `<p class="card-text">${item.price}</p>`;
                newContent += `<button id="btn-${item.id}" class="btn btn-success" onClick="displayDetails(${item.id})">Show details</button>`;

                //hidden info
                newContent += `<div class="item-details" id="item-details-${item.id}" style="display: none;">`;
                newContent += `<p class="card-text">Price: ${item.price}</p>`;
                newContent += `<p>${item.description}</p>`;
                newContent += `<p>Brand: ${item.brand}</p>`;
                newContent += `<button class="btn btn-primary m-2" onClick="addWishlist('${item.title}', '${item.description}', '${item.img}', '${item.price}', '${item.brand}')">Add to Wishlist</button>`;
                newContent += `<button class="btn btn-info m-2" onClick="addCart('${item.title}', '${item.description}', '${item.img}', '${item.price}', '${item.brand}')">Add to Bag</button>`;
                newContent += `</div> </div> </div> </div>`;
            }
        });
        document.getElementById('books-list').innerHTML = newContent;

    }
};
xhr.open('GET', "./data.json", true);
xhr.send(null);