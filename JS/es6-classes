/* Classes with ES6
* ES6 brought us a new way of OOP with classes which looks similar to other programming languages.
* Classes should be fine in most modern browsers now.
* Classes under the hood in javascript work almost the same way we have been doing.
* Classes are just "syntax sugar".
*/

// a Person object
class Person {
    // the constructor for the person object
    constructor(firstName, lastName, dob) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.dob = new Date(dob);
    }

    // methods automatically get added to the prototype.
    greeting() {
        return `Hello there, ${this.firstName} ${this.lastName}`;
    }

    getAge() {
        const diff = Date.now() - this.dob.getTime();
        const ageDate = new Date(diff);
        return Math.abs(ageDate.getUTCFullYear() - 1970);
    }

    setLastName(newLastName) {
        this.lastName = newLastName;
    }
}

class SimpleAdder {
    // also support static methods
    static addNumbers(x, y) {
        return x + y;
    }
}

const person = new Person('Chad', 'Smith', '2-12-90');
person.setLastName('Johnson');
console.log(person);
console.log(person.getAge());
// we don't need to instantiate a SimpleAdder object to use the addNumbers method.
console.log(SimpleAdder.addNumbers(1, 2));
