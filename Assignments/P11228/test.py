import plotly.graph_objects as go

# Define node coordinates
node_x = [1, 2, 3, 4]
node_y = [1, 2, 1, 3]

# Define edge coordinates (pairs of nodes to connect)
edge_x = [1, 2, 3, 4]
edge_y = [1, 2, 1, 3]

# Create nodes scatter plot
nodes = go.Scatter(
    x=node_x,
    y=node_y,
    mode='markers',
    marker=dict(size=20)
)

# Create edges scatter plot
edges = go.Scatter(
    x=edge_x,
    y=edge_y,
    mode='lines',
    line=dict(width=1)
)

# Create the figure
fig = go.Figure(data=[nodes, edges])

# Update layout for a better visualization
fig.update_layout(
    showlegend=False
)

# Show the figure
fig.show()