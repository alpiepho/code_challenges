
// various online test questions from:
// https://www.testdome.com/d/javascript-interview-questions/2
// (I think I found a backdoor to the testdome site)

//========================================================================================
// 1. Ensure
// EASY 3min
// Implement the ensure function so that it throws an error if called 
// without arguments or the argument is undefined. Otherwise it should 
// return the given value.
function ensure(value) {
}
//   No argument throws an error: Wrong answer 
//   Truthy argument returns argument: Wrong answer 
//   Falsy argument is treated differently from undefined: Wrong answer 

function ensure(value) {
    if(value === undefined) {
        throw new Error('no arguments');
    }
    return value;
}
//  Ok 



//========================================================================================
// 2. Remove Property
// Implement the removeProperty function which takes an object and property name, and does the following:

// If the object obj has a property prop, the function removes the property from the object and 
// returns true; in all other cases it returns false.
function removeProperty(obj, prop) {
    return null;
}

// Property removed: Wrong answer 
// Correct return value: Wrong answer 

function removeProperty(obj, prop) {
	if (typeof obj[prop] === 'undefined')
  	return false
  delete obj[prop]
  return true
}

a = {}
a['one'] = 'one'
a['two'] = 'two'
a['three'] = 'three'
result = removeProperty(a, 'four')
console.log(result)
result = removeProperty(a, 'two')
console.log(result)
console.log(a)

//========================================================================================
// 3. Check Digit
// Your company assigns each customer a membership ID, and you are implementing a check digit for 
// those IDs.

// The check digit should be calculated by adding up all digits in each membership ID. If the 
// result of the sum is a number with more than a single digit, another iteration is required, 
// and the digits of the result also should be added together. This process should repeat until 
// a single-digit number is calculated.

// For example, for the membership ID "55555" the sum of all digits is 25. Because this is not 
// a single-digit number, 2 and 5 would be added, and the result, 7, would be the check digit.

function createCheckDigit(membershipId) {
    // Write the code that goes here.
    return 0;
}
  
console.log(createCheckDigit("55555"));

// Example case: Wrong answer 
// Single iteration required: Wrong answer 
// Two iterations required: Wrong answer 
// Multiple iterations required: Wrong answer 

function createCheckDigit(membershipId) {
	m = membershipId
	while(true) {
		let r = m.split("")
  	let s = r.reduce((prev, c) => {
  		return prev + parseInt(c,10)
  	}, 0)
    if (s < 10) return s;
    m = s.toString()
  }
    // Write the code that goes here.
    return 0;
}

console.log(createCheckDigit("55555"));


//========================================================================================
// 4. Date
// Write a function that converts user entered date formatted as M/D/YYYY to a format required 
// by an API (YYYYMMDD). The parameter "userDate" and the return value are strings.

// For example, it should convert user entered date "12/31/2014" to "20141231" suitable for the API.

function formatDate(userDate) {
    // format from M/D/YYYY to YYYYMMDD
}
  
console.log(formatDate("12/31/2014"));
console.log(createCheckDigit("55555"));

// Example case: Wrong answer 
// Two-digit month and day: Wrong answer 
// One-digit day: Wrong answer 
// One-digit month: Wrong answer 

//========================================================================================

// 5. Image Gallery
// An image gallery is a set of images with corresponding remove buttons. This is the HTML 
// code for a gallery with two images:

// <div class="image">
//   <img src="https://goo.gl/kjzfbE" alt="First">
//   <button class="remove">X</button>
// </div>
// <div class="image">
//   <img src="https://goo.gl/d2JncW" alt="Second">
//   <button class="remove">X</button>
// </div>
// Implement the setup function that registers a click event handler and implements the 
// following logic: When the button of class remove is clicked, its parent <div> element 
// should be removed from the gallery.

// For example, after the first image has been removed from the gallery above, it's HTML 
// code should look like this:

// <div class="image">
//   <img src="https://goo.gl/d2JncW" alt="Second">
//   <button class="remove">X</button>
// </div>
// DifficultyEasy 
// Time10min

function setup() {
    // Write your code here.
}
  
// Example case. 
document.body.innerHTML = `
<div class="image">
<img src="https://goo.gl/kjzfbE" alt="First">
<button class="remove">X</button>
</div>
<div class="image">
<img src="https://goo.gl/d2JncW" alt="Second">
<button class="remove">X</button>
</div>`;

setup();

document.getElementsByClassName("remove")[0].click();
console.log(document.body.innerHTML);

// Example case: Wrong answer 
// Remove single image: Wrong answer 
// Remove multiple images: Wrong answer

//========================================================================================
// 6. Closures
// Fix the bugs in the registerHandlers function. An alert should display anchor's zero-based 
// index within a document instead of following the link.

// For example, in the document below, the alert should display "2" when Google anchor is 
// clicked since it is the third anchor element in the document and its zero-based index is 2.

function registerHandlers() {
  var as = document.getElementsByTagName('a');
  for (var i = 0; i < as.length; i++) {
    as[i].onclick = function() {
      alert(i);
      return false;
    }
  }
}

/* HTML code for testing purposes (do not submit uncommented):
<body>
  In my life, I used the following web search engines:<br/>
  <a href="//www.yahoo.com">Yahoo!</a><br/>
  <a href="//www.altavista.com">AltaVista</a><br/>
  <a href="//www.google.com">Google</a><br/>
</body>
*/

// Example case: Wrong answer 
// Duplicate links: Wrong answer 
// Various links: Wrong answer



//========================================================================================
// 7. Loop
// Function appendChildren should add a new child div to each existing div. New divs 
// should be decorated by calling decorateDiv.

// For example, after appendChildren is executed, the following divs:

function appendChildren(decorateDivFunction) {
    var allDivs = document.getElementsByTagName("div");
  
    for (var i = 0; i < allDivs.length; i++) {
      var newDiv = document.createElement("div");
      decorateDivFunction(newDiv);
      allDivs[i].appendChild(newDiv);
    }
}
  
// Example case. 
document.body.innerHTML = `
<div id="a">
<div id="b">
</div>
</div>`;

//appendChildren(function(div) {});
console.log(document.body.innerHTML);


// Example case: Exception 
// Appending divs: Exception 
