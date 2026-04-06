class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
                # Step 1: pair position & time
        cars = [(pos, (target - pos) / spd) for pos, spd in zip(position, speed)]
        
        # Step 2: sort by position (descending)
        cars.sort(reverse=True)
        
        fleets = 0
        max_time = 0
        
        # Step 3: process cars
        for pos, time in cars:
            if time > max_time:
                fleets += 1
                max_time = time
        
        return fleets