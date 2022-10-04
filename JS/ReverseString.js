var string = "Welcome to this Javascript!";
function reverseBySeparator(string, separator) {
  return string.split(separator).reverse().join(separator);
}

var reverseEntireSentence = reverseBySeparator(string, "");
var reverseEachWord = reverseBySeparator(reverseEntireSentence, " ");
console.log(reverseEntireSentence) // !tpircsavaJ siht ot emocleW
console.log(reverseEachWord) //emocleW ot siht tpircsavaJ !
