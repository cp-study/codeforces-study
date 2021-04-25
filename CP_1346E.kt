import kotlin.math.pow

val UNREACHABLE= 2* 10.0.pow(5.0).toInt()
fun main(args: Array<String>) {
    val (N,M,K) = readLine()!!.split(" ").map { s -> s.toInt() }
    var dp = Array(N+1) { UNREACHABLE }
    dp[K]=0
    for (i in 1..M){
        val (x,y) = readLine()!!.split(" ").map { s -> s.toInt() }
        var xVar:Int=dp[x]
        var yVar:Int=dp[y]
        dp[x]= minOf(xVar+1,yVar)
        dp[y]= minOf(xVar,yVar+1)
    }
    dp.slice(1..N)
        .forEach { v -> if(v==UNREACHABLE) print("-1 ") else print("$v ") }
}