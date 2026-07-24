import heapq

def solution(n, paths, gates, summits):
    isSummit = set(summits)
    isGate = set(gates)
    
    graph = [[] for _ in range(n + 1)]
    for u, v, w in paths:
        graph[u].append((v, w))
        graph[v].append((u, w))
        
    intensity = [float('inf')] * (n + 1)
    pq = []
    for gate in gates:
        heapq.heappush(pq, (0, gate));
        intensity[gate] = 0
        
    while pq:
        w, curr = heapq.heappop(pq)
        
        if (w > intensity[curr]): continue
        if (curr in isSummit): continue
        
        for nxt, nxt_w in graph[curr]:
            if (nxt in isGate): continue
            
            nxt_intensity = max(w, nxt_w)
            if (nxt_intensity < intensity[nxt]):
                intensity[nxt] = nxt_intensity
                heapq.heappush(pq, (nxt_intensity, nxt))
    
    summits.sort()
    
    bestSummit = -1
    minIntensity = float('inf')
    
    for summit in summits:
        if (intensity[summit] < minIntensity):
            minIntensity = intensity[summit]
            bestSummit = summit
    
    return [bestSummit, minIntensity]