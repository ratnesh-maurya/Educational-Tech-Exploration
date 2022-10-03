//map method 
const numbers = [3,4,6,1,8];

const square = function(number){
    return number*number;
}

const squareNumber =  numbers.map(square);
console.log(squareNumber);  


const users = [
    {firstName :"Aditi", age : 23},
    {firstName :"Shruti", age : 20},
    {firstName :"Anagha", age : 22},
    {firstName :"Moksha", age : 21},
]

const UserName = users.map(user=>{
    return user.firstName;
})

console.log(UserName);
