package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// github.com/EndlessCheng/codeforces-go
func CF1009F(_r io.Reader, _w io.Writer) {
	out := bufio.NewWriter(_w)
	defer out.Flush()
	_i, buf := 1<<12, make([]byte, 1<<12)
	rc := func() byte {
		if _i == 1<<12 {
			_r.Read(buf)
			_i = 0
		}
		b := buf[_i]
		_i++
		return b
	}
	r := func() (x int) {
		b := rc()
		for ; '0' > b; b = rc() {
		}
		for ; '0' <= b; b = rc() {
			x = x*10 + int(b&15)
		}
		return
	}

	n := r()
	g := make([][]int, n)
	for i := 1; i < n; i++ {
		v, w := r()-1, r()-1
		g[v] = append(g[v], w)
		g[w] = append(g[w], v)
	}

	hson := make([]int, n)
	var _f func(v, fa int) int
	_f = func(v, fa int) int {
		maxDep, hs := 0, -1
		for _, w := range g[v] {
			if w != fa {
				if mxD := _f(w, v); mxD > maxDep {
					maxDep, hs = mxD, w
				}
			}
		}
		hson[v] = hs
		return maxDep + 1
	}
	_f(0, -1)

	ans := make([]int, n)
	var f func(v, fa int) ([]int, int)
	f = func(v, fa int) (cnt []int, maxI int) {
		if hson[v] == -1 {
			return []int{1}, 0
		}
		cnt, maxI = f(hson[v], v)
		for _, w := range g[v] {
			if w != fa && w != hson[v] {
				subCnt, _ := f(w, v)
				shift := len(cnt) - len(subCnt)
				for i, c := range subCnt {
					i += shift
					if cnt[i] += c; cnt[i] >= cnt[maxI] {
						maxI = i
					}
				}
			}
		}
		cnt = append(cnt, 1)
		if cnt[maxI] == 1 {
			maxI++
		}
		ans[v] = len(cnt) - 1 - maxI
		return
	}
	f(0, -1)
	for _, v := range ans {
		Fprintln(out, v)
	}
}

func main() { CF1009F(os.Stdin, os.Stdout) }
