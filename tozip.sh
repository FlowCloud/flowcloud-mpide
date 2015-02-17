git archive -v -o WiFire_Flow.zip HEAD $(git diff --name-only `git rev-list --parents HEAD | egrep "^[a-f0-9]{40}$"` HEAD | grep -v tozip.sh)
