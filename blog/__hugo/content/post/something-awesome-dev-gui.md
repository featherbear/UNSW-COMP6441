---
title: "Something Awesome: User Interface with Electron"
date: 2019-06-15T22:08:44+10:00

categories: ["Assessments", "Something Awesome"]
hiddenFromHomePage: false
postMetaInFooter: false

flowchartDiagrams:
  enable: false
  options: ""

sequenceDiagrams: 
  enable: false
  options: ""

---

[Vue]: https://vuejs.org/
[Vue.js]: https://vuejs.org/

Having a crack at Electron was a very fun experience - something that I've never tried before.  

Albeit I do have a little pet peeve with Electron, mainly that it uses WebKit.  
WebKit is great - don'get me wrong.

**But**  

Hi.  
I.  
Don't.  
Have.  
Anymore.  
RAM.  
To.  
Give.  
You.  

---

I also learnt to use the [Vue.js] Javascript framework - Helpful for piecing different website components together with modularity and ease.

---

I originally opted _out_ from using [Vuex](https://vuex.vuejs.org/), which is [Vue]'s state management library - but soon came to realise that it was **incredibly useful**.  

Essentially you can define methods that are required to be used in order to modify a value.

It did come with its quirks and niches.

Until I stumbled upon [this GitHub issue page](https://github.com/SimulatedGREG/electron-vue/issues/733), I spent many hours fraught upon trying to get my event dispatcher to work.

I had to remove the `createSharedMutations` plugin in order for it to work.

---

I guess, one of the things that turned me off with using JS frameworks, is not knowing how they work behind the scenes. Personally I like to understand how exactly something works before using it - and with the sheer complexity and size of [Vue], [React](https://reactjs.org/), even [Angular](https://angular.io/) - it was quite overwhelming.

Once I got started though, it wasn't too bad.  

I used the [Buefy](https://buefy.org/) library, which was a [Vue] integration of the [Bulma](https://bulma.io/) CSS framework that I've recently been playing around with.

I quite liked how you were able to scope your CSS stylings between components, and that each component had its own reactive data states.

|||
|:--:|:--:|
|![](preview_left.png)|![](preview_right.png)|

---

![](final.png)
