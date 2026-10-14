class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        q = []

        for i in range(len(position)):
            heapq.heappush(q, (-position[i], speed[i]))

        st = []

        while q:
            negative_position, car_speed = heapq.heappop(q)

            position = -negative_position
            time = (target - position) / car_speed

            # This car catches the fleet ahead
            if st and time <= st[-1]:
                continue

            # This car creates a new fleet
            st.append(time)

        return len(st)