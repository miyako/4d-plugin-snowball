# 4d-plugin-snowball
4D implementation of [Snowball: A language for stemming algorithms](http://snowball.tartarus.org)

Example
---
```
$text:="Le français est une langue indo-européenne de la famille des langues romanes."

  //your responsibility to clean the text
$text:=Lowercase(Replace string($text;".";"";*);*)

Snowball ($text;$words;$stems;Snowball_French)
```

###Supported languages:

* Snowball_Danish 0
* Snowball_Dutch 1
* Snowball_English 2
* Snowball_Finnish 3
* Snowball_French 4
* Snowball_German 5
* Snowball_Hungarian 6
* Snowball_Italian 7
* Snowball_Norwegian 8
* Snowball_Portuguese 9
* Snowball_Romanian 10
* Snowball_Russian 11
* Snowball_Spanish 12
* Snowball_Swedish 13
* Snowball_Turkish 14
