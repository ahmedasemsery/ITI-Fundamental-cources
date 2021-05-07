<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
		<html>
			<body>
				<h2>My CD Collection</h2>
				<table border="1">
					<tr bgcolor="#9acd32">
						<th>Title</th>
						<th>Artist</th>
						<th>Price</th>
						<th>Country</th>
					</tr>
					<xsl:for-each select="catalog/cd[year > 1990]">
						<xsl:sort select="country" />
						<tr>
							<xsl:apply-templates select="title"/>
							<xsl:apply-templates select="artist"/>
							<xsl:apply-templates select="price"/>
							<xsl:apply-templates select="country"/>
						</tr>
					</xsl:for-each>
				</table>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="title">
		<td>
			<xsl:value-of select="." />
		</td>
	</xsl:template>

	<xsl:template match="artist">
		<td>
			<xsl:value-of select="." />
		</td>
	</xsl:template>

	<xsl:template match="price">
		<xsl:choose>
			<xsl:when test=". &gt; 10 ">
				<td bgcolor="#ff0000">
					<xsl:value-of select="."/>
				</td>
			</xsl:when>
			<xsl:when test=". &gt; 8 ">
				<td bgcolor="#0000ff">
					<xsl:value-of select="."/>
				</td>
			</xsl:when>
			<xsl:otherwise>
				<td bgcolor="#00ff00">
					<xsl:value-of select="."/>
				</td>
			</xsl:otherwise>
		</xsl:choose>
	</xsl:template>

	<xsl:template match="country">
		<td>
			<xsl:value-of select="."/>
		</td>
	</xsl:template>
</xsl:stylesheet>