
<div>
<p align="center">
	<a href="https://www.42sp.org.br/">
		<img src="./.github/42.png" alt="42" width="500"/> 
	</a>
</p>
</div>
<p align="center">	
   <a href="https://www.linkedin.com/in/luiz-lima-cezario/">
      <img alt="Luiz Cezario" src="https://img.shields.io/badge/-luizCezario-682998?style=flat&logo=Linkedin&logoColor=white" />
   </a>

  <a aria-label="Completed" href="https://www.42sp.org.br/">
    <img src="https://img.shields.io/badge/42.sp-Philosophers-682998?logo="></img>
  </a>
  <a href="https://github.com/luizlcezario/Philosophers/commits/master">
    <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/luizlcezario/Philosophers?color=682998">
  </a> 

  <a href="https://github.com/luizlcezario/Philosophers/stargazers">
    <img alt="Stargazers" src="https://img.shields.io/github/stars/luizlcezario/Philosophers?color=682998&logo=github">
  </a>
</p>

<div align="center">
  <sub>Push Swap of 42. Make with ❤︎ for
        <a href="https://github.com/luizlcezario">Luiz Cezario</a> 
    </a>
  </sub>
</div>


# Philosophers
In computer science, The Dining Philosopher Problem is an example problem often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them.

## What is Philosophers?
Philosophers is an individual project at 42 that requires us to solve The Dining Philosopher Problem problem using threads, processes, mutex and semaphores. The mandatory part must be solved using threads and mutex. The solution was implemented using a monitoring thread, which checks if any philosopher has died and warns others to stop (locking mutex). The bonus consists of using processes instead of threads and semaphores instead of mutex, to solve it the solution used was to implement the death check between the sleeping times, avoiding the problem of reporting the death of a philosopher with more than 10ms.

## Problem statement
The problem was proposed by Edsger W. Dijkstra in 1965 and is considered one of the classic problems about operating systems. The problem consists of five philosophers sitting around a circular dinner table, where each philosopher has a plate for eating spaghetti and a fork to his right. To eat they need 2 forks but there is only one fork between each pair of plates. A philosopher has three actions: eating, thinking, or sleeping. When a philosopher gets hungry he will try to take the fork to his right and to his left, one at a time. If he manages to get both forks, he will eat the food at a certain time and will put the forks on the table, going to sleep and then going to think again.

## Test

	```bash
	$> make
	$> ./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep  [number_of_times_each_philosopher_must_eat]

	```

> I never thought philosophy would be so deadly	

Give ⭐️ if you like this project, this will help me!

