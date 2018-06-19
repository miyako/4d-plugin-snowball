# 4d-plugin-snowball
4D implementation of [Snowball: A language for stemming algorithms](http://snowball.tartarus.org)

### Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|<img src="https://cloud.githubusercontent.com/assets/1725068/22371562/1b091f0a-e4db-11e6-8458-8653954a7cce.png" width="24" height="24" />|

### Version

<img src="https://cloud.githubusercontent.com/assets/1725068/18940649/21945000-8645-11e6-86ed-4a0f800e5a73.png" width="32" height="32" /> <img src="https://cloud.githubusercontent.com/assets/1725068/18940648/2192ddba-8645-11e6-864d-6d5692d55717.png" width="32" height="32" /> <img src="https://user-images.githubusercontent.com/1725068/41266195-ddf767b2-6e30-11e8-9d6b-2adf6a9f57a5.png" width="32" height="32" />

### Releases

[2.0](https://github.com/miyako/4d-plugin-snowball/releases/tag/2.0)

![preemption xx](https://user-images.githubusercontent.com/1725068/41327179-4e839948-6efd-11e8-982b-a670d511e04f.png)

**Compatibility break** 

changed output params from array to text (json collection). previous version available in [``array``](https://github.com/miyako/4d-plugin-snowball/tree/array) branch

## Syntax

```
status:=Snowball (words;symbols;stems;lang)
```

Parameter|Type|Description
------------|------------|----
words|TEXT|
symbols|TEXT|``JSON`` array (out)
stems|TEXT|``JSON`` array (out)
lang|LONGINT|see constants
status|LONGINT|

### Examples

```
$text:="Le français est une langue indo-européenne de la famille des langues romanes."

  //your responsibility to clean the text
$text:=Lowercase(Replace string($text;".";"";*);*)

Snowball ($text;$words_json;$stems_json;Snowball French)

C_COLLECTION($words;$stems)

$words:=JSON Parse($words_json)
$stems:=JSON Parse($stems_json)

ALERT(String($words.length))
ALERT(String($stems.length))
```

<img width="451" alt="2018-06-19 10 30 48" src="https://user-images.githubusercontent.com/1725068/41570938-dd305a2a-73ab-11e8-813a-074f7ffd451e.png">

#### Supported languages:

* Snowball Danish 0
* Snowball Dutch 1
* Snowball English 2
* Snowball Finnish 3
* Snowball French 4
* Snowball German 5
* Snowball Hungarian 6
* Snowball Italian 7
* Snowball Norwegian 8
* Snowball Portuguese 9
* Snowball Romanian 10
* Snowball Russian 11
* Snowball Spanish 12
* Snowball Swedish 13
* Snowball Turkish 14
