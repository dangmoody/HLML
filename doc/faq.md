# FAQs

Why don't you just put all the generated code into one massive header?
===
A couple of reasons:
* It would ultimately slow down compile times.
* Being able to include individual vector/matrix/quaternion types into specific headers where you need them is very useful.
* With the amount of code that gets generated it's nice to split down headers into vector/matrix/quaternion functions for better code browseability.


Have you ever thought about releasing the generator as well?  That way, people could generate only the maths types that they need!
===
TL;DR - I'm not sure.

I've thought about this a couple of times.  I'm in two minds about it.  On one hand:
* Giving the user control and options is good.
* The user would probably only be generating certain types, which keeps the amount of code to compile down, leading to faster compile times.

These are good things.

On the other hand:
* We're not just shipping code anymore.
* There's more to document.
* There's more that the user would have to understand to use the library.

These are not-so-ideal things.

I always debate this idea though.  If people can make enough convincing arguments for doing it or not doing it.  I'd love to hear their thoughts.