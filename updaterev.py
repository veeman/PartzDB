import string
import subprocess
import sys

gitRevision = -1

if len(sys.argv) < 2:
    sys.exit(1)

try:
    gitRevision = subprocess.check_output(['git', 'rev-list', 'HEAD', '--count'])
except:
    sys.exit(2)

gitRevision = int(gitRevision)

if gitRevision < -1:
    sys.exit(2)


# Open a file
fo = open(sys.argv[1], "r+")

line = fo.readlines()
for idx, item in enumerate(line):
   if '#define VERSION_BUILD' in item:
        item = "#define VERSION_BUILD\t\t" + str(gitRevision) + "\n"
        if line[idx] == item:
            gitRevision = -1;
        line[idx] = item

if gitRevision > 0:
    fo.seek(0)
    for idx, item in enumerate(line):
        fo.write(item)
    fo.truncate()

# Close opend file
fo.close()
