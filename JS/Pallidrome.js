const Palindrome = (input) => {
		var rem, temp, final = 0;
		var number = input

		temp = number;
		while(number>0)
		{
			rem = number%10;
			number = parseInt(number/10);
			final = final*10+rem;
		}
		if(final==temp)
		{
			console.log("Number is Pallidrome")
		}
		else
		{
			console.log("Number is not Pallidrome")
		}
}
//INVOKING METHOD
Palindrome(123)
