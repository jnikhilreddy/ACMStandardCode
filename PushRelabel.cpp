/*Push Relabel Algorithm for Network Flow by chormen*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
#define INF 10000
#define min(a, b) (a < b ? a : b)

long node, edge, source, sink, srcConnect, snkConnect, count;

long mat[MAX][MAX], flowMat[MAX][MAX];
long nodeHeight[MAX], excessFlow[MAX], nodeCapacity[MAX];

void initializePreFlow(void)
{
	long uNode;

	memset(excessFlow, 0, sizeof(excessFlow));
	memset(nodeHeight, 0, sizeof(nodeHeight));
	memset(flowMat, 0, sizeof(flowMat));

	nodeHeight[source] = node;

	for(uNode = 0; uNode < node; uNode++)
	{
		if(mat[source][uNode])
		{
			flowMat[source][uNode] = mat[source][uNode];
			flowMat[uNode][source] = - mat[source][uNode];
			excessFlow[uNode] = mat[source][uNode];
		}

		count++;
	}
}

void pushFlow(long uNode, long vNode)
{
	long increase;

	increase = min(excessFlow[uNode], mat[uNode][vNode] - flowMat[uNode][vNode]);
	increase = min(increase, nodeCapacity[vNode] - excessFlow[vNode]);

	flowMat[uNode][vNode] += increase;
	flowMat[vNode][uNode] = -flowMat[uNode][vNode];
	excessFlow[uNode] -= increase;
	excessFlow[vNode] += increase;

	count++;
}

void liftNode(long uNode)
{
	long vNode, minHeight;

	for(minHeight = 0; minHeight < node; minHeight++)
	{
		if(mat[uNode][minHeight] > flowMat[uNode][minHeight])
			break;

		count++;
	}

	for(vNode = minHeight + 1; vNode < node; vNode++)
	{
		if(mat[uNode][vNode] > flowMat[uNode][vNode])
		{
			if(nodeHeight[vNode] < nodeHeight[minHeight])
			{
				minHeight = vNode;
			}
		}

		count++;
	}

	nodeHeight[uNode] = nodeHeight[minHeight] + 1;
}

void genericPreFlowPush(void)
{
	long uNode, vNode, currentFlow, lift, option = 1;

	initializePreFlow();

	while(option)
	{
		option = 0;
		for(uNode = 1; uNode < node - 1; uNode++)
		{
			if(excessFlow[uNode] > 0)
			{
				currentFlow = 0;
				lift = 1;

				for(vNode = 0; vNode < node; vNode++)
				{
					if(vNode != uNode)
					{
						if(mat[uNode][vNode] > flowMat[uNode][vNode])
						{
							currentFlow = 1;
							if(nodeHeight[uNode] <= nodeHeight[vNode])
								continue;
							lift = 0;
							if(nodeHeight[uNode] == nodeHeight[vNode] + 1)
							{
								option = 1;
								pushFlow(uNode, vNode);
								if(!excessFlow[uNode])
									break;
							}
						}
					}

					count++;
				}

				if(currentFlow && lift)
				{
					option = 1;
					liftNode(uNode);
					uNode -= 1;
				}
			}
		}
	}
}

void main(void)
{
	long ind, flow, netFlow, uNode, vNode;

	while(scanf("%ld", &node) == 1)
	{
		for(ind = 1; ind <= node; ind++)
		{
			scanf("%ld", &nodeCapacity[ind]);
		}

		count = source = 0;
		sink = node + 1; node += 2;
		nodeCapacity[source] = nodeCapacity[sink] = INF;

		memset(mat, 0, sizeof(mat));

		scanf("%ld", &edge);
		for(ind = 1; ind <= edge; ind++)
		{
			scanf("%ld %ld %ld", &uNode, &vNode, &flow);
			mat[uNode][vNode] = flow;

			count++;
		}
		
		scanf("%ld %ld", &srcConnect, &snkConnect);
		for(ind = 1; ind <= srcConnect; ind++)
		{
			scanf("%ld", &vNode);
			mat[source][vNode] = nodeCapacity[vNode];

			count++;
		}

		for(ind = 1; ind <= snkConnect; ind++)
		{
			scanf("%ld", &vNode);
			mat[vNode][sink] = INF;

			count++;
		}

		genericPreFlowPush();

		for(vNode = 1, netFlow = 0; vNode < node; vNode++)
		{
			netFlow += flowMat[source][vNode];

			count++;
		}

		printf("flow = %ld count = %ld\n", netFlow, count);
	}
}