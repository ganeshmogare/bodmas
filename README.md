

# bodmas
bodmas is a nodemodule using which you can do the simple maths operations like addition ,subtraction ,multiplication and devision.

install node module 
 
 `npm install bodmas` 
 
bodmas has 4 methods 
* `bodmas.add(a,b)` returns strigified value sum of a nad b
* `bodmas.subtract(a,b)` returns difference of a and b
* `bodmas.multiply(a,b)` returns product of a nd b
* `bodmas.devide(a,b)` returns quotient od a and b

>Examples:
```
  var bodmas = require('bodmas'); 
  var a = 100.48;
  var b = 30;
  var sum = parseFloat(bodmas.add(a,b));// will return 130.48
  var difference = bodmas.subtract(a,b);// will return 70.48
  var product = bodmas.multiply(100,10);// will return 1000
  var quotient = bodmas.devide(100,10);// will return 10
  ```
  
  This module is written mainly to avoid the floating point value errors in javascript.
Hope this helps someone 🎉🌮
