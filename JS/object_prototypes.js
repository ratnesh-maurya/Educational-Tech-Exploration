/* Creating objects with Object.create
*/

// our person prototypes
const personPrototypes = {
    greeting: function() {
        return `Hello there, ${this.firstName} ${this.lastName}`;
    },
    setLastName: function(newLastName) {
        this.lastName = newLastName;
    }
}

const person = Object.create(personPrototypes);
person.firstName = 'Chad';
person.lastName = 'Smith';
person.age = 28;

console.log(person.greeting());
person.setLastName("Robinson");
console.log(person.greeting());
 
// another way to create objects
const person2 = Object.create(personPrototypes, {
    firstName: {value: 'Chad'},
    lastName: {value: 'Smith'},
    age: {value: 28}
});

console.log(person2);
