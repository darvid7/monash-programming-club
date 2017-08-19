import os

name_map = {
    'sampleChairs': 'F',
    'sampleLetters': 'G',
    'sampleTables': 'H',
    'I-sampleplanes': 'I',
    'J-sampletree': 'J',
    'K-samplepacking': 'K',
    'L-sampledomino': 'L',
    'M-sampleinfinite': 'M',
    'N-sampleCompetition': 'N',
    'O-sampleschoolpairing': 'O'
}

files = os.listdir()
for filename in files:
    bits = filename.split('.')

    if filename.endswith('py'):
        continue
    if len(bits) == 2:
        base, count, ext = bits[0], '1', bits[1]
    else:
        assert len(bits) == 3
        base, count, ext = bits
    if base.startswith('sample') and len(base) == len('sampleA'):
        continue
    newname = 'sample' + name_map[base] + '.' + count + '.' + ext
    print("Renaming {} to {}".format(filename, newname))
    os.rename(filename, newname)
