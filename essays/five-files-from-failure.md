---
layout: essay
type: essay
title: "Five Files from Failure"
# All dates must be YYYY-MM-DD format!
date: 2024-09-26
published: true
labels:
  - ESLint
  - Coding Standards
  - Visual Studio Code
  - Software Engineering
  - Essay
---

## About ESLint
[ESLint](https://eslint.org/) – “an open source project that helps you find and fix problems with your JavaScript code.” This is one of the first sentences used to describe the pluggable linting utility for JavaScript and JSX. ESLint implements a set of guidelines for writing clean, readable, and maintainable code, among other things. This set of guidelines is more commonly known as *coding standards*. ESLint is capable of analyzing code to find problems according to its set coding standards quickly and offers to fix problems automatically where errors occur. This tool is what I have used for the last week (in tandem with [VSCode](https://code.visualstudio.com/) to complete assignments that meet ESLints coding standards).
## The Application (of Coding Standards)
The past two assignments that I’ve completed were practice WODs (about WODs – see this [essay](https://github.com/kaenasylva/kaenasylva.github.io/blob/main/essays/the-typescript-tower-of-babel.md)) that focused on solving one of the five problems presented by Santiago Valdarrama in a blog post titled, [Five programming problems every Software Engineer should be able to solve](https://web.archive.org/web/20200414191515/http://www.shiftedup.com/2015/05/07/five-programming-problems-every-software-engineer-should-be-able-to-solve-in-less-than-1-hour). The instructions for these WODs went something like this:
Start your timer.
Create an empty GitHub repository and clone it to your local computer.
Open the local repository in VSCode.
Set up your project to use our (ICS 314) coding standards. Download five files into your project directory: .eslintrc.js, .eslintignore, .gitignore, package.json, tsconfig.json
Invoke `npm install` to install ESLint.
Implement a code that solves (answers) the question, make sure ESLint has no problems with your code, and commit the finished program to GitHub.
Stop your timer.
## Setting Up ESLint
Now, believe it or not – installing ESLint and using it to adhere to coding standards is *by far* the most painful part of both WODs. One of the pains of the setup for me (on Windows 10) involved installing… a lot of different things. I ran into several issues during the setup, which resulted in some error messages about incompatible versions and installations that are no longer supported. Anyway, I was able to get ESLint to work. More or less.
Once ESLint was working, I was able to start working on the WOD. The problems themselves are not the focus of this paper, so I won’t be breaking them down here (if you’d like to try them for yourself, you can refer to the link above). When it came to dealing with the ESLint errors, I experienced a few migraines. Some of the fixes were simple: fix indentation; add a new line at the end of the code. Some of the fixes were hard: return type placed incorrectly around an arrow function; functional programming types undefined. What’s nice is, like I mentioned before, ESLint is capable of offering automatic fixes to errors that it finds. That being said, as long as your code doesn’t have any *serious* errors, then ESLint should be able to fix it with the click of a button.
## Five Files From… Success?
So far, I’ve put ESLint and coding standards in a questionable light. I do believe, however, that applying coding standards with ESLint has some benefits. When it comes to programming – especially *functional* programming – ESLint can be very helpful. It can help people become better programmers and, in my case, can teach new ways of formatting working code. Take for example this function that I wrote for a WOD last week:
```js
const numEvenNums = (nums: number[]): number => {
	Return nums.filter(num => num % 2 === 0).length;
};
```
This function, called `numEvenNums`, takes an array of numbers (in this case, the first 50 numbers of the Fibonacci sequence) and returns the total number of even numbers that occur. This snippet of code *should* work, but ESLint has a problem with it: “Unexpected block statement surrounding arrow body; move the returned value immediately after the `=>`. This is what ESLint wanted me to do:
```js
const numEvenNums = (nums: number[]): number => nums.filter(num => num % 2 === 0).length;
```
ESLint wanted me to change the format of the arrow function, which narrowed it down to one line of code, rather than the three lines it took up earlier. Here, coding standards taught me a way to format arrow functions that I was formerly unaware of. I’m still fresh when it comes to TypeScript and the way that it handles functions, so corrections like this that I would otherwise be unaware of can be very helpful.
## In Conclusion
I think that ESLint is a helpful tool. While the setup and following coding standards may be tiresome, it is a worthwhile investment that can teach new ways to code. Fixing the formatting errors also tickles an OCD itch in my brain, so that’s nice. I believe that most of the issues I ran into had to do with universal setup instructions for different operating systems. ESLint seems to have some problems with installation because Windows 10 does not support certain files needed to run it successfully. That combined with end-of-support for user-maintained projects led to one big headache that *almost* drove me insane. The short version? I had problems manually setting up ESLint to check for coding standards. All things considered (and setup aside), I actually enjoy using ESLint. It provides a nice outline for uniform coding and offers insight into coding standards. Moving forward, I think it’d be helpful to use an IDE with built-in coding standards or a plugin(s) that does something similar, but that’s just me. 

If you’ve read all of this and are planning to use ESLint with VSCode, good luck, and happy coding! If not, I hope I’ve provided you with the motivation to use some form of coding standard in your next project. Have fun!
