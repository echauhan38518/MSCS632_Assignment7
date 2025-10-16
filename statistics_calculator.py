class StatisticsCalculator:
    def __init__(self, numbers):
        self.numbers = numbers

    def mean(self):
        return sum(self.numbers) / len(self.numbers)

    def median(self):
        sorted_nums = sorted(self.numbers)
        n = len(sorted_nums)
        mid = n // 2
        if n % 2 == 0:
            return (sorted_nums[mid - 1] + sorted_nums[mid]) / 2
        else:
            return sorted_nums[mid]

    def mode(self):
        frequency = {}
        for num in self.numbers:
            frequency[num] = frequency.get(num, 0) + 1
        max_freq = max(frequency.values())
        modes = [num for num, freq in frequency.items() if freq == max_freq]
        # Return single mode if only one exists, otherwise all modes
        return modes[0] if len(modes) == 1 else modes

if __name__ == "__main__":
    data = [24, 92, 88, 86, 24, 93, 42]
    stats = StatisticsCalculator(data)
    #print results
    print(f"Mean: {stats.mean():.2f}")
    print(f"Median: {stats.median():.2f}")
    print(f"Mode: {stats.mode()}")