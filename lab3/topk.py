from mrjob.job import MRJob
from mrjob.step import MRStep


class TopTenWords(MRJob):
    def steps(self):
        return [
            MRStep(mapper=self.mapper, reducer=self.reducer),
            MRStep(reducer = self.reducer2)
            ]
   
    def mapper(self, _, line):
        arr = line.split()
        stopwords = ["for", "as", "the", "is", "at", "which", "on", "in", "at", "or", "an", "a", "if", "and"]
        for item in arr:
            if item.lower() not in stopwords:
                yield item.lower(), 1

    def reducer(self, key, values):
        yield None, (int(sum(values)), key)

    def reducer2(self, key, values):
        arr = []
        for value in values:
          arr.append(value)
        temp = []
        for i in range(10):
         temp.append(max(arr))
         arr.remove(max(arr))
        for i in range(10):
          yield temp[i]

if __name__ == '__main__':
    TopTenWords.run()










