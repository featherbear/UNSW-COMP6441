---
title: "Where You At"
date: 2019-07-25T03:48:38+10:00

categories: ["Musings"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

_Google knows quite a lot about where I've been, apparently._  

I've been using Google Maps since around 2010.  
And since around 2010, Google has been storing my location history on their servers.

I decided request a copy of my location history from [Google Takeout](https://takeout.google.com) to see what they know  
(_or at least what they want to tell us that they know_).  
I selected the _Location History (as JSON)_ option, waited for my archive to get created and downloaded the files.  
Then I wrote a Python script to extract the information and plot the location data onto a map.

* I used the [SimpleKML Python library](http://simplekml.readthedocs.io/) to help with this
* I used [GPXSee](https://www.gpxsee.org/) to visualise the data

And well...
Oh boy.  
Google knew **a lot**.

# Map

## Overview

Below is a map of my travels in the last 4 years.  
_Anything past 4 years worth of data - and my computer couldn't handle displaying all the 864647 data points at once..._

![](overview.png)

Doesn't look like that much to be honest, it shows that I've been to different parts of Australia, the United States, and a handful of Asian and European countries.  
But let's take a closer look.

## Map (Sydney)

If we zoom the map into just the Sydney area, we can get a pretty good overview of my travels.  

![](plots_sydney.png)

Quite a heavy presence down south - perhaps I might live there or something?

# Conclusion

It's quite frightening actually to know that Google retains my location data since around 2010.  

And mind you, the map images above only show 4 years worth of data.  
There's still another 5 or so other years unrevealed.

9 years worth of location history. ***MY*** location history.

---

But of course, I knew that they had this data.  

The decision to use Google Maps.  
The decision to use a smartphone with a GPS module.  
The decision to press "I Accept" on the terms and conditions.

We all _know_ that other people have our data.  
We trade our privacy for convenience - and in some cases we're okay with that, other times not so much.

---

What about you?  
What does Google know about you?

# Code

```python
import json
import simplekml

def iterateData(data):
  for point in data:
    ts = int(point["timestampMs"])
    lat = int(point["latitudeE7"]) / 10000000
    long = int(point["longitudeE7"]) / 10000000
    yield(ts, (lat, long))

print("Parsing...")

data = json.load(open("Location History.json", "r"))

data = data['locations']

print("There are %d data points" % len(data))

fCount = 0
i = 0

kml = None
pieces = []

for timestamp, (lat, long) in iterateData(data):
  if i % 190000 == 0 and i != 0 and False:
    kml = simplekml.Kml()
    kml.newlinestring(name="line", coords=pieces)
    kml.save(f"output{fCount}.kml")
    pieces = []
    fCount += 1
  pieces.append((long,lat))
  i += 1

if len(pieces) > 0:
  kml = simplekml.Kml()
  kml.newlinestring(name="line", coords=pieces)
  kml.save(f"output{fCount}.kml")
```