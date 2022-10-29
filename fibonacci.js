var fibonacci = (
  
  function()
  {
     var arr = {};
     function fun1(n) 
    {
    var value;
    if (n in arr)
    {
      value = arr[n];
    } 
    else 
    {
      if (n === 0 || n === 1)
      value = n;
      else
      value = fun1(n-1)+fun1(n - 2);
      arr[n] = value;
    }
    return value;
  }
 return fun1;
}) ();
