---
layout: project
type: project
image: img/navigation.jpg
title: "Navigation Routes"
date: 2024-11-03
published: true
labels:
  - Graphs
  - Python
  - Shortest Paths
  - Team Project
summary: "A graph-pathing team project that I worked on for ICS 311."
---

## Overview

This assignment asked for three people to work on an assignment inspired by the history of Polynesian Navigation. The overview was as follows...

> The Polynesian Triangle is the collection of islands within the triangle of Hawaii, Rapanui (Easter Island) and Aotearoa (New Zealand). Historically, canoes have traveled between the islands within the triangle and most likely beyond. This assignment is to plan a comprehensive collection of routes to distribute useful food and items, to circulate visitors amongst the sea of  islands, and identify ways to provide assistance between islands when necessary.

Ultimately, it asked for our group to (given a collection of islands, their populations, and travel times between them) describe different algorithms to share resources and move people across the sea of islands.

## The Problem

This project offered one problem for each person in the group to provide an implementation for. My problem was this...

> How to ensure that skilled leaders can share their knowledge across the sea of islands. Leaders want to share their knowledge with everyone in a hands-on way, and so they must visit as many islands in as short a time as possible. Leaders need to repeat these trips, as the leaders themselves learn new skills, and as new people grow up and need to learn the skills too. A single leader uses a single canoe to share their knowledge across the islands. Your approach should consider the recency of skill sharing by a leader, and should prioritize the highest populations.

## The Solution

The approach I took to solving this problem was representing the sea of islands as a directed, weighted graph with each island as a node and each route between islands as a directed edge (with a travel time). I used a priority queue to prioritize visits to islands based on population size and the time since each island’s last visit, and an adjacency list to store each island’s neighbors. Islands and routes between then were represented by nodes and edges.

This is what my data structures looked like:

```py
class Island:
    def __init__(self, id, population):
        self.id = id
        self.population = population
        self.neighbors = []
        self.last_visit = -1  # Track the last visit time for skill-sharing

class Edge:
    def __init__(self, destination, travel_time):
        self.destination = destination
        self.travel_time = travel_time

class SeaOfIslandsGraph:
    def __init__(self):
        self.islands = {}

    def add_island(self, id, population):
        island = Island(id, population)
        self.islands[id] = island

    def add_route(self, from_id, to_id, travel_time):
        from_island = self.islands[from_id]
        to_island = self.islands[to_id]
        edge = Edge(to_island, travel_time)
        from_island.neighbors.append(edge)
```

I used a function called `share_skills`, structured around a priority-based depth-first search (DFS) for skill sharing. This allows leaders to prioritize islands with the highest populations and the longest time since the last visit. The function utilized an attribute called `last_visit` that allows the algorithm to determine how recently each island has been visited.

```py
def share_skills(graph, start_id, current_time):
    # Priority queue for islands ordered by (-population, time_since_last_visit)
    visit_priority_queue = []
    heapq.heappush(visit_priority_queue, (-graph.islands[start_id].population, current_time, graph.islands[start_id]))

    visited = set()

    while visit_priority_queue:
        _, last_visit_time, current_island = heapq.heappop(visit_priority_queue)
        current_island.last_visit = current_time  # Update last visit time
        visited.add(current_island.id)

        for edge in current_island.neighbors:
            neighbor = edge.destination
            if neighbor.id not in visited:
                # Calculate time priority (longer time since last visit gives higher priority)
                time_priority = current_time - neighbor.last_visit if neighbor.last_visit != -1 else current_time
                # Push to priority queue with highest population and recency priority
                heapq.heappush(visit_priority_queue, (-neighbor.population, time_priority, neighbor))
```

## Conclusion

This was a fun project to work on! I learned important skills required for working with others on a group project. I also built work habits that led me to success with ICS 311 group projects for the rest of the semester. This assignment helped me to better understand directed, weighted graphs and shortest path algorithms.

If you're interested in seeing the other problems and my teammates' solutions to them, you can find that stuff [here](https://docs.google.com/document/d/1hHK9oWiJMnbDiDMGU4mjFEk2Y_D0GzIo2nKjpR88JTM/edit?usp=sharing).
