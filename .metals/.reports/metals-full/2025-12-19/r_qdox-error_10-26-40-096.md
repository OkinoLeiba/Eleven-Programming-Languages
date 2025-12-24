error id: file://<WORKSPACE>/CodeWars/Java.java
file://<WORKSPACE>/CodeWars/Java.java
### com.thoughtworks.qdox.parser.ParseException: syntax error @[103,5]

error in qdox parser
file content:
```java
offset: 3283
uri: file://<WORKSPACE>/CodeWars/Java.java
text:
```scala
package CodeWars;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedHashMap;

public class Java {

    // Create a function taking a positive integer between 1 and 3999 (both
    // included) as its parameter
    // and returning a string containing the Roman Numeral representation of that
    // integer.

    // Modern Roman numerals are written by expressing each digit separately
    // starting with the leftmost digit
    // and skipping any digit with a value of zero. There cannot be more than 3
    // identical symbols in a row.

    // In Roman numerals:

    // 1990 is rendered: 1000=M + 900=CM + 90=XC; resulting in MCMXC.
    // 2008 is written as 2000=MM, 8=VIII; or MMVIII.
    // 1666 uses each Roman symbol in descending order: MDCLXVI.
    // Example:

    // 1 --> "I"
    // 1000 --> "M"
    // 1666 --> "MDCLXVI"

    // {'M', 1000},
    // {'D', 500},
    // {'C', 100},
    // {'L', 50},
    // {'X', 10},
    // {'V', 5},
    // {'I', 1},
    public static String roman_numerals(int num) {
        StringBuilder result = new StringBuilder();
        LinkedHashMap<Integer, String> roman_table = new LinkedHashMap<Integer, String>();
        
        roman_table.put(1000, "M");
        roman_table.put(900, "CM");
        roman_table.put(500, "D");
        roman_table.put(400, "CD");
        roman_table.put(100, "C");
        roman_table.put(90, "XC");
        roman_table.put(50, "L");
        roman_table.put(40, "XL");
        roman_table.put(10, "X");
        roman_table.put(9, "IX");
        roman_table.put(5, "V");
        roman_table.put(4, "IV");
        roman_table.put(1, "I");
        
        for (int key : roman_table.keySet()) {
            if (key <= num) {
                int count = Math.floorDiv(num, key);
                int i = 0;
                while (i < count) {result.append(roman_table.get(key)); ++i;}
                num -= (count * key);
            }
        }


        return result.toString();
    }

    // Complete the solution so that it splits the string into pairs of two characters.
    // If the string contains an odd number of characters then it should replace the mi
    // second character of the final pair with an underscore ('_').
    //
    // Examples:
    //
    //  'abc' =>  ['ab', 'c_']
    //  'abcdef' => ['ab', 'cd', 'ef']

    public static String[] split_strings(String s) {
        ArrayList<String> result = new ArrayList<String>();
        // String[] result = new String[s.length()/2];
        for (int i = 0; i < s.length(); i += 2) {
            // int j = 0;
            if (i + 1 < s.length()) {
                result.add(s.substring(i, i + 2));
                // result[j] = s.substring(i, i+2);
                // j++;
            } else {
                result.add(s.substring(i, i + 1) + '_');
            }

        }

        return result.toArray(new String[0]);
    }
    
    // Create  function that returns the sum of the two lowest positive
    // numbers given an array of minimum 4 positive integers.
    // No floats or non - positive integers will be passed.

    // For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

    // [10, 343445353, 3453445, 3453545353453] should return 3453455.

    p@@ublic static long 

    /*************** Main Method ***************/
    public static void main(String[] args) {
        roman_numerals(1666);
        // split_strings("abcdef");
    }
}

```

```



#### Error stacktrace:

```
com.thoughtworks.qdox.parser.impl.Parser.yyerror(Parser.java:2025)
	com.thoughtworks.qdox.parser.impl.Parser.yyparse(Parser.java:2147)
	com.thoughtworks.qdox.parser.impl.Parser.parse(Parser.java:2006)
	com.thoughtworks.qdox.library.SourceLibrary.parse(SourceLibrary.java:232)
	com.thoughtworks.qdox.library.SourceLibrary.parse(SourceLibrary.java:190)
	com.thoughtworks.qdox.library.SourceLibrary.addSource(SourceLibrary.java:94)
	com.thoughtworks.qdox.library.SourceLibrary.addSource(SourceLibrary.java:89)
	com.thoughtworks.qdox.library.SortedClassLibraryBuilder.addSource(SortedClassLibraryBuilder.java:162)
	com.thoughtworks.qdox.JavaProjectBuilder.addSource(JavaProjectBuilder.java:174)
	scala.meta.internal.mtags.JavaMtags.indexRoot(JavaMtags.scala:49)
	scala.meta.internal.metals.SemanticdbDefinition$.foreachWithReturnMtags(SemanticdbDefinition.scala:99)
	scala.meta.internal.metals.Indexer.indexSourceFile(Indexer.scala:546)
	scala.meta.internal.metals.Indexer.$anonfun$reindexWorkspaceSources$3(Indexer.scala:677)
	scala.meta.internal.metals.Indexer.$anonfun$reindexWorkspaceSources$3$adapted(Indexer.scala:674)
	scala.collection.IterableOnceOps.foreach(IterableOnce.scala:630)
	scala.collection.IterableOnceOps.foreach$(IterableOnce.scala:628)
	scala.collection.AbstractIterator.foreach(Iterator.scala:1313)
	scala.meta.internal.metals.Indexer.reindexWorkspaceSources(Indexer.scala:674)
	scala.meta.internal.metals.MetalsLspService.$anonfun$onChange$2(MetalsLspService.scala:912)
	scala.runtime.java8.JFunction0$mcV$sp.apply(JFunction0$mcV$sp.scala:18)
	scala.concurrent.Future$.$anonfun$apply$1(Future.scala:691)
	scala.concurrent.impl.Promise$Transformation.run(Promise.scala:500)
	java.base/java.util.concurrent.ThreadPoolExecutor.runWorker(ThreadPoolExecutor.java:1095)
	java.base/java.util.concurrent.ThreadPoolExecutor$Worker.run(ThreadPoolExecutor.java:619)
	java.base/java.lang.Thread.run(Thread.java:1447)
```
#### Short summary: 

QDox parse error in file://<WORKSPACE>/CodeWars/Java.java