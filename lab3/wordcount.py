from mrjob.job import MRJob


class WordFreq(MRJob):

    def mapper(self, _, line):
        arr = line.split()
        stopwords = ["for", "as", "the", "is", "at", "which", "on", "in", "at", "or", "an", "a", "if", "and"]
        for item in arr:
            if item.lower() not in stopwords:
                yield item.lower(), 1

    def reducer(self, key, values):
        yield key, sum(values)


if __name__ == '__main__':
    WordFreq.run()
