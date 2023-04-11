<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<html>
			<head>
				<title>Employee Information</title>
			</head>
			<body>
				<table border="1">
					<tr>
						<th>Name</th>
						<th>Home Phone</th>
						<th>Work Phone</th>
						<th>Mobile Phone</th>
						<th>Email</th>
						<th>Address</th>
					</tr>
					<xsl:for-each select="employees/employee">
						<tr>
							<td><xsl:value-of select="name"/></td>
							<td><xsl:value-of select="phones/phone[@type='home']"/></td>
							<td><xsl:value-of select="phones/phone[@type='work']"/></td>
							<td><xsl:value-of select="phones/phone[@type='mobile']"/></td>
							<td><xsl:value-of select="email"/></td>
							<td>
								<xsl:for-each select="addresses/address">
									<xsl:value-of select="concat(street, buildingNumber, Region, city, country)"/><br/>
								</xsl:for-each>
							</td>
						</tr>
					</xsl:for-each>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
