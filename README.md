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

**Compatibility break** changes params from array to text (json collection)

## Syntax

```
status:=Snowball (words;symbols;stems;lang)
```

Parameter|Type|Description
------------|------------|----
words|TEXT|
symbols|TEXT|``JSON`` array (out)
stems|TEXT|``JSON`` array (out)
lang|TEXT|see constants
status|LONGINT|


### Examples

```
$text:="Le français est une langue indo-européenne de la famille des langues romanes."

  //your responsibility to clean the text
$text:=Lowercase(Replace string($text;".";"";*);*)

Snowball ($text;$words;$stems;Snowball_French)
```

#### Supported languages:

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
